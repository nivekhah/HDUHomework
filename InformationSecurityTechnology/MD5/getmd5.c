#include "md5.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

void getmd5(FILE *f, char dest[32])
{
    assert(f != NULL);

    md5_state_t state;
    md5_byte_t digest[16];
    char buffer[448];
    size_t cnt;

    md5_init(&state);
    while ((cnt = fread(buffer, sizeof(char), 448, f)) != 0)
        md5_append(&state, (const md5_byte_t *)buffer, cnt);
    md5_finish(&state, digest);

    for (int di = 0; di < 16; ++di)
        sprintf(dest + di * 2, "%02x", digest[di]);
}
