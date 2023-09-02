/*
 * Include required headers
 */
#include <stddef.h>  // for size_t
#include "utils.h"
#include "gluethread/glthread.h"

/*
 * Maximum size for storing keys in Notification Chain Elements
 */
#define MAX_NOTIF_KEY_SIZE	64

/*
 * Enum to represent operation codes for Notification Chain
 */
typedef enum {
    NFC_UNKNOWN,
    NFC_SUB,
    NFC_ADD,
    NFC_MOD,
    NFC_DEL,
} nfc_op_t;

/*
 * Function to return string representation of operation codes
 */
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

/*
 * Typedef for the application callback function
 */
typedef void (*nfc_app_cb)(void *, size_t, nfc_op_t, uint32_t);

/*
 * Data structure for Notification Chain Element
 */
typedef struct notif_chain_elem_ {
    char key[MAX_NOTIF_KEY_SIZE]; // Array to store the key
    size_t key_size;              // Size of the key
	uint32_t subs_id;             // Subscriber ID
    bool_t is_key_set;            // Flag to indicate if key is set
    nfc_app_cb app_cb;            // Function pointer to the application callback
    glthread_t glue;              // Required for linking elements in the list
} notif_chain_elem_t;

// Macro to convert glthread to notif_chain_elem
GLTHREAD_TO_STRUCT(glthread_glue_to_notif_chain_elem,
                   notif_chain_elem_t, glue);

/*
 * Data structure for Notification Chain
 */
typedef struct notif_chain_ {
    char nfc_name[64];              // Optional name for the chain
    glthread_t notif_chain_head;    // Head of the notification chain
} notif_chain_t;

/*
 * Function prototypes
 */

// Create a new Notification Chain
notif_chain_t *nfc_create_new_notif_chain(char *notif_chain_name);

// Delete all Notification Chain Elements in the chain
void nfc_delete_all_nfce(notif_chain_t *nfc);

// Register a new Notification Chain Element to the chain
void nfc_register_notif_chain(notif_chain_t *nfc,
                              notif_chain_elem_t *nfce);

// Invoke the notification chain
void nfc_invoke_notif_chain(notif_chain_t *nfc,
                            void *arg, size_t arg_size,
                            char *key, size_t key_size,
							nfc_op_t nfc_op_code);
