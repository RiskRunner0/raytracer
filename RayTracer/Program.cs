using Raytracer.Math;
using System;
using Tuple = Raytracer.Math.Tuple;
using RayTracer.Drawing;

namespace RayTracer
{
    class Program
    {
        static void Main(string[] args)
        {
            IFileWriter writer = new PPMFileWriter();
            var canvas = new Canvas(900, 550);

            var p = new Projectile(
                new Point(0, 1, 0),
                new Vector(1, 1.8f, 0).NormalizedVector * 11.25
                );
            var e = new Environment(
                new Vector(0, (float)-0.1, 0),
                new Vector((float)-0.01, 0, 0)
                );

            int counter = 0;
            while(p.position.y > 0)
            {
                Console.WriteLine($"{counter++} - Pos: ({p.position.x}, {p.position.y}, {p.position.z}), Vel: ({p.velocity.x}, {p.velocity.y}, {p.velocity.z})");
                canvas.UpdatePixel((int)Math.Floor(p.position.x), canvas.height - (int)Math.Floor(p.position.y), new Color(1, 0, 0));
                p = tick(e, p);
            }

            writer.WriteToFile(canvas);
        }

        static Projectile tick(Environment env, Projectile proj)
        {
            var position = proj.position + proj.velocity;
            var velocity = proj.velocity + env.gravity + env.wind;
            return new Projectile(position, velocity);
        }
    }

    class Projectile
    {
        public Projectile(Tuple position, Tuple velocity)
        {
            this.position = position;
            this.velocity = velocity;
        }

        public Tuple position;
        public Tuple velocity;
    }

    class Environment
    {
        public Environment(Vector gravity, Vector wind)
        {
            this.gravity = gravity;
            this.wind = wind;
        }

        public Vector gravity;
        public Vector wind;
    }
}
