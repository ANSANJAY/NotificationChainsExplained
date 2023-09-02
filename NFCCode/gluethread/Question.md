
## Questions 🤔

### Basics 🌱

1. **Q1**: Can you explain what the purpose of a notification chain is based on what you've seen in `notif.h`?
   - **Answer**: A notification chain is essentially a linked list of callbacks, often used for implementing observer patterns. When an event happens, all registered subscribers (callbacks) are notified. 

### Data Structures 🏗️

2. **Q2**: What are the core data structures used to implement a notification chain in `notif.h`?
   - **Answer**: Two main data structures are used: `notif_chain_elem_t` for individual elements in the chain and `notif_chain_t` for the chain itself.

3. **Q3**: What does the `glthread_t glue;` member in `notif_chain_elem_t` represent?
   - **Answer**: It likely serves as the linked list node for this element within the notification chain, enabling us to 'glue' elements together in the list. The library `gluethread/glthread.h` probably provides linked list functionalities.

### Enums and Typedefs 🗂️

4. **Q4**: What is `nfc_op_t` and how is it used?
   - **Answer**: `nfc_op_t` is an enumeration representing different operation types (e.g., Subscribe, Add, Modify, Delete). It's likely used when invoking the chain to specify what kind of operation to perform.

5. **Q5**: Can you explain what `nfc_app_cb` is?
   - **Answer**: `nfc_app_cb` is a typedef for a function pointer. The function takes a `void *` argument, a `size_t` argument specifying the size of the first argument, an `nfc_op_t` operation code, and a `uint32_t` which might be a unique ID for the subscriber.

### Functions 🛠️

6. **Q6**: What is the purpose of the `nfc_create_new_notif_chain` function?
   - **Answer**: This function is used to create a new notification chain and likely initializes it with a name.

7. **Q7**: How would you use `nfc_invoke_notif_chain`?
   - **Answer**: This function is used to trigger the notifications in the chain. You would pass the relevant data and keys to it, and it would go through the chain, invoking the callbacks that meet the criteria.

8. **Q8**: What does `nfc_delete_all_nfce` do?
   - **Answer**: This function likely removes all elements from a given notification chain, essentially emptying it.

### Callbacks and Keys 🗝️

9. **Q9**: How are keys managed in the notification chain?
   - **Answer**: Each element (`notif_chain_elem_t`) has a `key` and `key_size`. The key is an array of characters, and `key_size` specifies the actual size of the key stored.

10. **Q10**: What do you understand by a 'wildcard subscriber'? 
    - **Answer**: A 'wildcard subscriber' is one that doesn't specify a key, effectively saying that it's interested in all messages, regardless of their key. This is represented by setting `is_key_set` to `false`.

## Advanced ⭐

11. **Q11**: Can you explain the `GLTHREAD_TO_STRUCT` macro's role in the `notif.h` file?
    - **Answer**: `GLTHREAD_TO_STRUCT` is likely a macro used to retrieve the main struct (`notif_chain_elem_t`) from its `glthread_t glue` member, effectively providing a way to navigate from list node to containing structure.

12. **Q12**: How would you extend this notification chain to support priority levels among subscribers?
    - **Answer**: One way could be to add a priority level member in the `notif_chain_elem_t` struct. Then, during the invocation in `nfc_invoke_notif_chain`, you'd traverse the chain based on priority levels before calling the registered callbacks.

Feel free to ask for explanations on any of these questions! 🎓
