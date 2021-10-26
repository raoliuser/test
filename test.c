#include <stdio.h>
#include <stdint.h>

typedef char RCP_INT8;
typedef unsigned char RCP_UINT8;
typedef short RCP_INT16;
typedef unsigned short RCP_UINT16;
typedef int RCP_INT32;
typedef unsigned int RCP_UINT32;
typedef unsigned long long RCP_UINT64;
typedef float RCP_FLOAT;
typedef double RCP_DOUBLE;
typedef unsigned char RCP_BOOL;
typedef struct rcp_counter64 {
	RCP_UINT32 high;
	RCP_UINT32 low;
} RCP_C64;

#define RCP_HEADER_LENGTH sizeof(RCP_NISAC_MESSAGE_HEAD)

#define MAX_ONE_STRING_NUM 4
#define UD_NUM 39
#define RCP_MAX_DATA_BLOCK_PER_MESSAGE 255
#define MAX_INFO_BUF_SIZE 1000
#define MAX_STRING_BUFFER_LEN 128

/* Message header */
typedef struct tag_RCP_NISAC_MESSAGE_HEAD {
	RCP_UINT8 flag;
	RCP_UINT8 msg_type;
	RCP_UINT16 msg_code;
	RCP_UINT32 msg_id;
	RCP_UINT8 more_flag;
	RCP_UINT8 length;
	RCP_UINT8 blocktype;
	RCP_UINT8 data_block_num;
	RCP_UINT8 payload[0];
} RCP_NISAC_MESSAGE_HEAD;

struct ow_cli_sys_info_t {
    uint32_t cuid;
    uint8_t rule_type;
    uint8_t save;       //  dynamic rule use, 2 string, 3 combine
    uint8_t safe;
    uint8_t ori_is_nomask;
    uint8_t action; //0:drop, 1:fw
    uint8_t user_id;
    uint8_t rule_flag;
    uint8_t aging_type;
    uint8_t is_front;
    uint16_t action_id;
    uint32_t aging_flow;
    uint32_t aging_time;
    uint32_t inner_rule_id;
    uint32_t nvi_rule_id;
    uint32_t customer_rule_id;
    uint32_t rule_config_time;	//from 1970.0101 0hour 0second
    uint32_t host_ip;
    uint8_t dynamic_bind_flag;
    uint16_t dynamic_bind_pattern;
    uint8_t valid;
    uint32_t taskid;
};

struct rule_size_t{
	unsigned short min_size;
	unsigned short max_size;	
};

struct ow_ud_t {
	unsigned short data;
	unsigned short mask;
};

struct ow_string_t {
    char string_buffer[MAX_STRING_BUFFER_LEN+1]; 
    uint16_t string_hex_flag;
    uint16_t string_offset_type; //0:float; 1:fix
    uint16_t string_offset_start;
    uint16_t string_offset_end;
};

struct string_entry_t{
	uint32_t se_mask;
	struct ow_string_t string_entrys[MAX_ONE_STRING_NUM];
};

struct phone_entry_t{
	int			type;
	uint64_t	value;
};

struct class_entry_cli_t {  //928
    unsigned int size;
    unsigned int key_mask;
    unsigned int protocol;
    unsigned int protocol_mask;
    unsigned int sip;
    unsigned int sip_mask;
    unsigned int dip;
    unsigned int dip_mask;
    unsigned short sport;
    unsigned short sport_mask;
    unsigned short dport;
    unsigned short dport_mask;
    unsigned short tcp_flag;
    struct rule_size_t size_range;    //4
    unsigned short sipv6[8];
    unsigned short sipv6_mask[8];
    unsigned short dipv6[8];
    unsigned short dipv6_mask[8];
    unsigned short ip_version;	 
    long long ud_mask;
    struct ow_ud_t uds[UD_NUM];   //4
    unsigned int grp_key;
    unsigned int grp_key_mask;
    unsigned int vlan_id;
    struct string_entry_t string_entry;  //556
    struct phone_entry_t phone_entry;  //16
    unsigned char ingroup;
    struct ow_cli_sys_info_t sys_info;  //56
};

struct Rule_B { //936   align(8)
	struct class_entry_cli_t class_entry;  //928
	RCP_UINT32 outgroup_id;  //4 
};

// Data block  //Note: the struct size must be times of 4.
typedef struct tag_RCP_NISAC_DATA_BLOCK {
    union {
        struct Rule_B Rule;
    };
} RCP_NISAC_DATA_BLOCK;

struct rcp_msg_params_s {
	RCP_UINT32 msg_id;
	RCP_UINT8 more_flag;
	RCP_UINT8 nparam;			// used by data block message
	RCP_UINT16 info_len;		//used by show info message
	union {
		RCP_NISAC_DATA_BLOCK params[RCP_MAX_DATA_BLOCK_PER_MESSAGE];	// used by data block message
		char info_buf[MAX_INFO_BUF_SIZE];	//used by show info message
	} params_list;
};

int main()
{
    printf("%ld\n", sizeof(struct ow_cli_sys_info_t));
    return 0;
}