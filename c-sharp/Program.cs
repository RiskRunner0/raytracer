using System;

namespace raytracer
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");

            IFileWriter writer = new PPMFileWriter();
            writer.WriteToFile(new Color[,]);
        }
    }
}
