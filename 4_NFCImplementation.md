# Detailed Revision Notes for Notification Chain Implementation 📚

## Introduction 🎉
The video discusses implementing a generic Notification Chain system with two core functionalities: **Subscription** and **Notification Invocation**. 

## Core Functionalities 🛠️

### 1. Subscription Request (NFC Register Notification Chain) 📝

- **Purpose**: Allows a subscriber to register with the notification chain for event notifications.
- **How it works**: 
  1. The subscriber fills in the parameters for a notification chain element.
  2. Calls `NFC_register_notification_chain()` to register its element.

- **Function Signature**: 
  ```c
  void NFC_register_notification_chain(notif_chain_t *nfc, notif_chain_elem_t *nfce);
  ```
- **Arguments**: 
  - First: Pointer to Notification Chain (`notif_chain_t *nfc`)
  - Second: Notification Chain Element (`notif_chain_elem_t *nfce`)

- **Implementation Steps**:
  1. Create a copy of the passed-in `notif_chain_elem_t`.
  2. Insert the copy into the linked list represented by `notif_chain_t`.

### 2. Invoke Request (NFC Invoke Notification Chain) 📣

- **Purpose**: Triggered by the publisher to notify the subscribers.
- **How it works**: 
  1. Publisher specifies the chain to invoke and data to send.
  2. Calls `NFC_invoke_notification_chain()`.

- **Function Signature**: 
  ```c
  void NFC_invoke_notification_chain(notif_chain_t *nfc, void *arg, size_t arg_size, char *key, size_t key_size);
  ```
- **Arguments**: 
  - First: Pointer to Notification Chain
  - Second and Third: Data publisher wants to send (arg, arg_size)
  - Fourth and Fifth: Key (key, key_size)

- **Implementation Steps**:
  1. Iterate over the linked list.
  2. For each element, compare the key against the provided key.
  3. If a match or wildcard is found, invoke the callback.

---

## Advanced Considerations 🤔

### Wildcard Subscriptions ⭐

- If the key is not set in the chain element, it is considered a "wildcard" entry.
- A wildcard subscriber will receive notifications for any key.

### Extensibility 🌱

- The current setup is designed as a generic notification chain and can be extended.
- For example, adding a function to "unsubscribe" from the notification chain, although not implemented in the video.

## Interview Questions about this Topic 🎓

### Q1: Can you explain what a 'Subscription Request' in the context of Notification Chains is?
#### Answer: 
A 'Subscription Request' is an action where a subscriber registers itself to a notification chain for receiving event notifications. This is done via the function `NFC_register_notification_chain()`.

### Q2: What happens when a subscriber registers to a Notification Chain?
#### Answer: 
Upon registration, the subscriber's details are encapsulated in a `notif_chain_elem_t`. This element is then added to the linked list of the notification chain (`notif_chain_t`).

### Q3: What is the role of the 'Invoke Request' in the Notification Chain?
#### Answer: 
The 'Invoke Request' is triggered by the publisher to notify all subscribers in a notification chain. The function responsible for this is `NFC_invoke_notification_chain()`.

### Q4: How does the publisher notify the subscribers using `NFC_invoke_notification_chain()`?
#### Answer: 
The publisher specifies the chain to invoke and the data to send as arguments to the function. The function then iterates through the chain, matching keys and invoking callbacks for matching or wildcard entries.

### Q5: What are 'Wildcard Subscriptions'?
#### Answer: 
Wildcard subscriptions are entries in the notification chain that don't specify a key. These entries will receive notifications for any key.

### Q6: How would you extend this Notification Chain framework?
#### Answer: 
One way to extend it would be to add a function to allow subscribers to unsubscribe from the notification chain. Another way might be to introduce priority levels for the subscribers.

---

This should help you revise and prepare for your interviews! Good luck! 🍀
