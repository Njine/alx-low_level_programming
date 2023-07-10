#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 64

/**
* main - Entry point for ELF header reader program
* Description: program reads ELF header from file and writes information
* @argc: number of command-line arguments
* @argv: array of commandline argument strings
* Returns: 0 on success, 98 on failure
*/
int main(int argc, char *argv[])
{
int cm;
Elf64_Ehdr header;

if (argc != 2)
{
fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
return (98);
}

cm = open(argv[1], O_RDONLY);
if (cm == -1)
{
fprintf(stderr, "Error: Cannot open file '%s'\n", argv[1]);
return (98);
}

if (read_header(cm, &header) == -1)
{
fprintf(stderr, "Error: Cannot read header of file '%s'\n", argv[1]);
return (98);
}

check_elf(&header);
print_magic(&header);
print_class(&header);
print_data(&header);
print_version(&header);
print_abi(&header);
print_osabi(&header);
print_type(&header);
print_entry(&header);

close(cm);
return (0);
}

/**
* read_header - Reads the ELF header of a file into a header struct.
* @su: The file descriptor of the ELF file.
* @header: A pointer to an ELF header struct to read into.
*
* Description: function reads the ELF header of a file into a header struct.
* Returns: 0 on success, -1 on failure.
*/
int read_header(int su, Elf64_Ehdr *header)
{
if (lseek(su, 0, SEEK_SET) == -1)
{
return (-1);
}

if (read(su, header, sizeof(*header)) != sizeof(*header))
{
return (-1);
}

return (0);
}

/**
* check_elf - Checks if a file is an ELF file
* @header: A pointer to an ELF header.
*
* Description: If the file is not an ELF file - exit code 98.
*/
void check_elf(Elf64_Ehdr *header)
{
if (header->e_ident[EI_MAG0] != ELFMAG0 ||
header->e_ident[EI_MAG1] != ELFMAG1 ||
header->e_ident[EI_MAG2] != ELFMAG2 ||
header->e_ident[EI_MAG3] != ELFMAG3)
{
fprintf(stderr, "Error: Not an ELF file\n");
exit(98);
}
}

/**
* print_magic - Prints magic numbers of ELF header
* @header: A pointer to ELF header.
*
* Description: Magic numbers are separated by spaces.
*/
void print_magic(Elf64_Ehdr *header)
{
int f;
printf("  Magic:   ");
for (f = 0; f < EI_NIDENT; f++)
{
printf("%02x ", header->e_ident[f]);
}
printf("\n");
}

/**
* print_class - Prints ELF header class.
* @header: A pointer to ELF header.
*
* Description: Possible values are "ELF32" or "EL
*/