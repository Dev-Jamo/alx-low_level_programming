#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * analyze_elf - checks if a file is an ELF file
 * close_elf - descriptor as para and att to close the file
 *
 * Description: if the file is not an ELF file - exit code 98
 */

void analyze_elf(const char *filename);
void close_elf(int elf);

void analyze_elf(const char *filename)
{
	Elf64_Ehdr header;
	int o, r;

	o = open(filename, O_RDONLY);
	if (o == -1)
	{
	perror("Error: Can't open file");
	exit(98);
	}

	r = read(o, &header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
	perror("Error: Read failed");
	close_elf(o);
	exit(98);
	}
	if (header.e_ident[0] != 0x7f || header.e_ident[1] != 'E' ||
	header.e_ident[2] != 'L' || header.e_ident[3] != 'F')
	{
	dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
	close_elf(o);
	exit(98);
	}

	printf("ELF Header:\n");

	close_elf(o);
}

void close_elf(int elf)
{
	if (close(elf) == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
	exit(98);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
	fprintf(stderr, "Usage: %s <ELF_file>\n", argv[0]);
	(return 1;)
	}

	analyze_elf(argv[1]);

	(return 0;)
}
