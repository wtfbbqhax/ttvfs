
/* ttvfs example #4 - Example #1 re-done, now reading from a zip file. */

#include <cstdio>
#include <ttvfs.h>
#include <VFSZipArchiveLoader.h>

int main(int argc, char *argv[])
{
    ttvfs::VFSHelper vfs;

    vfs.AddLoader(new ttvfs::DiskLoader);

    // Make the VFS able to load Zip files
    vfs.AddArchiveLoader(new ttvfs::VFSZipArchiveLoader);


    // Mount an archive as a folder in the directory it resides in.
    vfs.AddArchive("test.zip");

    // Access the file as usual
    ttvfs::File *vf = vfs.GetFile("test.zip/zipped.txt");
    if(!vf || !vf->open("r"))
    {
        puts("ERROR\n"); // failed to find file
        return 1; 
    }

    char buf[513];
    size_t bytes = vf->read(buf, 512);
    buf[bytes] = 0;
    puts(buf);

    vf->close();

    return 0;
}
