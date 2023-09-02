# Notification Chain in Publisher-Subscriber Model Detailed Notes 📝

## Introduction 🌟
- **Publisher-Subscriber Model** in software systems involves components known as publishers and subscribers.
- Ideal for software systems divided into different modules or independent components.
  
## Terminology 👀
- **Publisher**: Owner of a data source (e.g., a routing table).
- **Subscriber**: Interested in the data owned by the publisher.
  
## Example Components 👨‍💻
- Components like `Application1`, `Application2`, `Application3`, and `Application4`.
- These components can run as independent threads in the same process, though they could also be part of different systems.

## Subscription Process 🤝
1. A subscriber sends a **subscription request** to the publisher, specifying interest in particular data and a callback function (`FA1`).
2. Upon receiving the request, the publisher creates an **entry in its notification chain**.
  
## Notification Chain 🚨
- A linked list maintained by the publisher.
- Stores the keys and callback functions of the subscribers.
- Can grow or shrink depending on the subscription or unsubscription requests.
  
## Callback Mechanism 🛎️
- When the publisher updates an entry in the data source, it walks through the notification chain.
- Invokes the **callbacks of the matching entries**.

## Wildcard Subscription 🌐
- Subscribers can also register without specifying any key, acting as a wildcard.
- These subscribers get notified for **all updates**.

# Interview Questions and Answers ❓👩‍💼

## Q1: What is the role of a Publisher in the Publisher-Subscriber Model?
### A1: 
The Publisher owns a particular data source, like a routing table, and notifies Subscribers when this data is updated or modified.

## Q2: How does a Subscriber show interest in a particular piece of data?
### A2: 
The Subscriber sends a subscription request to the Publisher specifying which data they are interested in and providing a callback function to be invoked when that data changes.

## Q3: What is a Notification Chain and who maintains it?
### A3: 
A Notification Chain is a linked list or database maintained by the Publisher. It stores information about the Subscribers, including the specific data they are interested in and their callback functions.

## Q4: How does a Publisher notify a Subscriber about data changes?
### A4: 
When the data source owned by the Publisher changes, the Publisher walks through its Notification Chain, finds Subscribers with matching interests, and invokes their registered callback functions.

## Q5: What does it mean when a Subscriber subscribes with a wildcard key?
### A5: 
A wildcard subscription means that the Subscriber is interested in all data changes, not just a specific entry. When any data changes, the Subscriber's callback function will be invoked.

## Q6: Can a Publisher maintain multiple Notification Chains?
### A6: 
Yes, if a Publisher has multiple data sources, it will maintain separate Notification Chains for each of its data sources.

## Q7: How can a Notification Chain grow or shrink?
### A7: 
A Notification Chain can grow when new Subscribers send subscription requests and can shrink when Subscribers send unsubscription requests.

## Q8: Can Subscribers be independent software systems?
### A8: 
Yes, Subscribers and Publishers can either be independent threads running in the same process or entirely separate software systems, possibly running on different machines.
