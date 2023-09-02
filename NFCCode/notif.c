// Ensure that the header file is included only once.
#ifndef __NOTIF_CHAIN_
#define __NOTIF_CHAIN_

// Include required header files.
#include <stddef.h>  /* for size_t */
#include "utils.h"
#include "gluethread/glthread.h"

// Maximum key size for notification chain elements.
#define MAX_NOTIF_KEY_SIZE 64

// Enum to define operation codes for the notification chain.
typedef enum {
	NFC_UNKNOWN,  // Unknown operation
	NFC_SUB,      // Subscribe
	NFC_ADD,      // Add
	NFC_MOD,      // Modify
	NFC_DEL,      // Delete
} nfc_op_t;

// Function to convert enum operation codes to string for debugging.
static inline char *nfc_get_str_op_code(nfc_op_t nfc_op_code) {
	static char op_code_str[16];
	switch(nfc_op_code) {
		case NFC_UNKNOWN: return "NFC_UNKNOWN";
		case NFC_SUB: return "NFC_SUB";
		case NFC_ADD: return "NFC_ADD";
		case NFC_MOD: return "NFC_MOD";
		case NFC_DEL: return "NFC_DEL";
		default: return NULL;
	}
}

// Typedef for the application callback function.
typedef void (*nfc_app_cb)(void *, size_t, nfc_op_t, uint32_t);

// Struct representing an individual element in the notification chain.
typedef struct notif_chain_elem_ {
    char key[MAX_NOTIF_KEY_SIZE];   // The key associated with this element
    size_t key_size;                // The size of the key
	uint32_t subs_id;               // Subscriber ID
    bool_t is_key_set;              // Flag to indicate if the key is set
    nfc_app_cb app_cb;              // Callback function pointer
    glthread_t glue;                // Glue for internal list management
} notif_chain_elem_t;

// Helper macro to get the struct from the list element.
GLTHREAD_TO_STRUCT(glthread_glue_to_notif_chain_elem,
                   notif_chain_elem_t, glue);

// Struct representing the notification chain.
typedef struct notif_chain_ {
    char nfc_name[64];                  // Human-readable name for the notification chain
    glthread_t notif_chain_head;        // Head of the notification chain
} notif_chain_t;

// Function to create a new notification chain.
notif_chain_t *nfc_create_new_notif_chain(char *notif_chain_name);

// Function to delete all elements from the notification chain.
void nfc_delete_all_nfce(notif_chain_t *nfc);

// Function to register a new element to the notification chain.
void nfc_register_notif_chain(notif_chain_t *nfc,
                     notif_chain_elem_t *nfce);

// Function to invoke the notification chain.
void nfc_invoke_notif_chain(notif_chain_t *nfc,
                       void *arg, size_t arg_size,
                       char *key, size_t key_size,
					   nfc_op_t nfc_op_code);

// End of the header file.
#endif /*  __NOTIF_CHAIN_  */
