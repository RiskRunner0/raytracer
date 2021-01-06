namespace RayTracer.Drawing 
{
    using System;
    using System.IO;

    public class PPMFileWriter: IFileWriter
    {
        private static int MAX_COLOR_VALUE = 255;
        private static int MAX_FILE_WIDTH = 70;
        private static string Header = "P3\n{0} {1}\n{2}\n";
        public PPMFileWriter()
        {

        }

        public void WriteToFile(Canvas canvas)
        {
            string docPath = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);
            using (var file = new StreamWriter(Path.Combine(docPath, "test.ppm")))
            {
                var height = canvas.height;
                var width = canvas.width;
                file.Write(String.Format(Header, width, height, MAX_COLOR_VALUE));

                for(int y = 0; y < height; ++y)
                {
                    for (int x = 0; x < width; ++x)
                    {
                        var line = $"{PPMFileWriter.GetColorAsString(canvas.GetPixel(x, y))} ";

                        file.Write(line);
                    }
                    
                    file.Write($"\n");
                }
            }
        }

        private static string GetColorAsString(Color c) => $"{PPMFileWriter.PrepareNumberForString(c.red * MAX_COLOR_VALUE)} {PPMFileWriter.PrepareNumberForString(c.green * MAX_COLOR_VALUE)} {PPMFileWriter.PrepareNumberForString(c.blue * MAX_COLOR_VALUE)}";

        private static int PrepareNumberForString(float f) => (int)Math.Ceiling(Math.Clamp(f, 0f, (float)MAX_COLOR_VALUE));
    }
}