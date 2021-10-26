#include <stdio.h>
#include <unistd.h>
#include <gnu/libc-version.h>

int main(int argc, char const *argv[])
{
    printf("glibc versin : %d.%d\n", __GLIBC__, __GLIBC_MINOR__);

    printf("glibc versin : %s\n", gnu_get_libc_version());

    char libc_version[16];
    confstr(_CS_GNU_LIBC_VERSION, libc_version, 16);
    printf("glibc versin : %s\n", libc_version);

    return 0;
}

#if 0
#define show_flag 1

[
    [
        {"interface\%s" : [i32, i32, i32]},
        [
            {"ngn_common_msg_header":0x1110} ,
            ["counter_name\%s", "counter_type\%s"],
            [
                ["name", show_flag],
                [show_flag,"type","total","rate"],
            ],
            [
                ["name", show_flag],
                [show_flag,"type","total","rate"],
            ],
            [
                ["name", show_flag],
                [show_flag,"type","total","rate"],
            ]
        ]
    ],
    [
        {"interface\%s" : [i32, i32, i32]},
        [
            {"ngn_common_msg_header":0b1110} ,
            ["counter_name\%s", "counter_type\%s"],
            [
                ["name", show_flag],
                [show_flag,"type","total","rate"],
            ],
            [
                ["name", show_flag],
                [show_flag,"type","total","rate"],
            ],
            [
                ["name", show_flag],
                [show_flag,"type","total","rate"],
            ]
        ]
    ],
    [
        {"interface\%s" : [i32, i32, i32]},
        [
            {"ngn_common_msg_header":0x1110} ,
            ["counter_name\%s", "counter_type\%s"],
            [
                ["name", show_flag],
                [show_flag,"type","total","rate"],
            ],
            [
                ["name", show_flag],
                [show_flag,"type","total","rate"],
            ],
            [
                ["name", show_flag],
                [show_flag,"type","total","rate"],
            ]
        ]
    ]

]
#endif