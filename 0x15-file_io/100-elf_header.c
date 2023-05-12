#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 64

int read_header(int fd, Elf64_Ehdr *header);
void check_elf(Elf64_Ehdr *header);
void print_magic(Elf64_Ehdr *header);
void print_class(Elf64_Ehdr *header);
void print_data(Elf64_Ehdr *header);
void print_version(Elf64_Ehdr *header);
void print_abi(Elf64_Ehdr *header);
void print_osabi(Elf64_Ehdr *header);
void print_type(Elf64_Ehdr *header);
void print_entry(Elf64_Ehdr *header);

/**
* main - Entry point for the ELF header reader program.
* @argc: The number of command-line arguments.
* @argv: An array of command-line argument strings.
*
* Description: This program reads an ELF header from a file and prints information about it.
* Returns: 0 on success, 98 on failure.
*/
int main(int argc, char *argv[])
{
int fd;
Elf64_Ehdr header;
if (argc != 2)
{
fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
exit(98);
}
fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
fprintf(stderr, "Error: Cannot open file '%s'\n", argv[1]);
exit(98);
}
if (read_header(fd, &header) == -1)
{
fprintf(stderr, "Error: Cannot read header of file '%s'\n", argv[1]);
exit(98);
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
close(fd);
return (0);
}

/**
* read_header - Reads the ELF header of a file into a header struct.
* @fd: The file descriptor of the ELF file.
* @header: A pointer to an ELF header struct to read into.
*
* Description: This function reads the ELF header of a file into a header struct.
* Returns: 0 on success, -1 on failure.
*/
int read_header(int fd, Elf64_Ehdr *header)
{
if (lseek(fd, 0, SEEK_SET) == -1)
{
return (-1);
}
if (read(fd, header, sizeof(*header)) != sizeof(*header))
{
return (-1);
}
return (0);
}

/**
* check_elf - Checks if a file is an ELF file.
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
* print_magic - Prints the magic numbers of an ELF header.
* @header: A pointer to an ELF header.
*
* Description: Magic numbers are separated by spaces.
*/
void print_magic(Elf64_Ehdr *header)
{
int i;
printf("  Magic:   ");


