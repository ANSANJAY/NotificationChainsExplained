# Implementing Notification Chain in TCP/IP Stack 🛠️

## Introduction 🌟
- Discusses the implementation of a generic notification chain in the files
- The aim is to create a data structure for notification chains in the TCP/IP stack.

## Data Structures 📦

### Notification Chain 🚨
- A linked list of function pointers coupled with keys.
- Contains two members:
  - **Name**: For user information only, doesn't add functionality.
  - **Head**: Points to the start of the linked list of callbacks.

### Notification Chain Element 📚
- A single node in the Notification Chain.
- Has four members:
  - **Key**: Memory allocated to store the key, bounded by `Max_Notify_Key_Size`.
  - **Key Size**: Actual size of the stored key.
  - **Boolean Flag**: Indicates whether a key is specified.
  - **Function Pointer**: Points to the subscriber's callback function.

## Constants 📝
- `Max_Notify_Key_Size` set to 64 bytes in this example.
  
## Callback Function Prototype 📞
- Should be generic to suit all types of data and subscribers.
- Accepts a `void*` type argument and another argument indicating its size in bytes.

# Interview Questions and Answers ❓👩‍💼

## Q1: What is a Notification Chain?
### A1: 
A Notification Chain is a linked list that holds function pointers and associated keys. 

## Q2: What does a Notification Chain Element represent?
### A2: 
- A Notification Chain Element is a single node in the Notification Chain linked list.
- It holds a key, the size of the key, a boolean flag indicating if a key is specified, and a function pointer for callbacks.

## Q3: What is `Max_Notify_Key_Size` and what's its significance?
### A3: 
`Max_Notify_Key_Size` is a constant value that represents the maximum size (in bytes) that can be allocated for storing keys in a Notification Chain Element. It's set to 64 bytes in this example.

## Q4: How is the callback function in the Notification Chain Element designed to be generic?
### A4: 
The callback function is designed to accept arguments of `void*` type and another argument specifying its size in bytes. This ensures that it can handle all types of data.

## Q5: How do you specify if a subscriber is a wildcard subscriber in the Notification Chain Element?
### A5: 
A boolean flag in the Notification Chain Element is used to indicate if a subscriber has specified a key or not. If not, the subscriber is considered a wildcard subscriber.

## Q7: Why does the Notification Chain have a 'Name' field, and what is its use?
### A7: 
The 'Name' field in the Notification Chain is optional and is solely for the user's information. It doesn't contribute to the chain's functionality.

## Q8: What operations would you need to perform on a Notification Chain?
### A8: 
The operations to perform would include adding new Notification Chain Elements, removing elements, and triggering the callback functions of matching elements.
