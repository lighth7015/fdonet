#include "backend.h"

int main(int args, char* arg[]) {
	const char* filename_fmt = "%s/packets/packetseq%d.aol";
	char *contents = NULL,
		 *filename = NULL;

	struct stat fileinfo = { 0 };

	if (args > 1) {
		asprintf(&filename, filename_fmt, dirname(arg[0]), atoi(arg[1]));

		if (stat(filename, &fileinfo) < 0) {
			printf("%s: No such file or directory.\n", filename);
		}
		else {
			FILE* handle = fopen(filename, "r");
			contents = calloc(fileinfo.st_size, sizeof(uint8_t));

			fread(contents, fileinfo.st_size, sizeof(uint8_t), handle);
			hexdump(contents, basename(filename), fileinfo.st_size);

			size_t hdrlen = sizeof(struct Header),
				offset = fileinfo.st_size - sizeof(struct Header);

			size_t length = fileinfo.st_size - hdrlen;

			protocol_header_t h = (protocol_header_t) contents;
			protocol_packet_t p = (protocol_packet_t) (contents + hdrlen);

			puts ("");
			hexdump((void *) h, "Packet header", hdrlen);

			puts ("");
			hexdump((void *) p, "Packet content", length);

			puts ("");
			puts ("Packet info-");

			g_write_log( "Request %-24s: %X, %x [%x + %x]", "magic/checksum",
						h->magic, h->checksum, CompCRC16( (uint8_t *) contents + offset, length),
											   CompCRC16( (uint8_t *) p, length ));

			g_write_log( "Machine %-24s: (%d, %d)", "resolution", p->xres, p->yres );
			g_write_log( "Machine %-24s: %d", "app memory", p->appmem );

			g_write_log( "Machine %-24s: %d", "video mode", p->video );
			g_write_log( "Machine %-24s: %x", "OS version", p->winversion );
		}
	}
	else {
		const char* appname = basename(arg[0]);
		printf("Directory: %s\nApp usage: %s [packet number]\n", dirname(arg[0]), appname);
	}

	return 0;
}
