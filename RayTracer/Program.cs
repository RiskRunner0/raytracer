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
            var canvas = new Canvas(10, 2);
            for(int y = 0; y < canvas.height; ++y)
            {
                for(int x = 0; x < canvas.width; ++x)
                {
                    canvas.UpdatePixel(x, y, new Color(1, 0.8, 0.6));
                }
            }
            writer.WriteToFile(canvas);

            var p = new Projectile(
                new Point(0, 1, 0),
                new Vector(1, 1, 0).NormalizedVector
                );
            var e = new Environment(
                new Vector(0, (float)-0.1, 0),
                new Vector((float)-0.01, 0, 0)
                );

            int counter = 0;
            while(p.position.y > 0)
            {
                Console.WriteLine($"{counter++} - Pos: ({p.position.x}, {p.position.y}, {p.position.z}), Vel: ({p.velocity.x}, {p.velocity.y}, {p.velocity.z})");
                p = tick(e, p);
            }
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
