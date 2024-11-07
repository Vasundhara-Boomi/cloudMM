import os
import multiprocessing

# Define the child_process function outside of the parent_child_communication function
def child_process(parent_to_child, child_to_parent):
    # Read message from the parent
    parent_message = parent_to_child.recv()
    print("Child: Received message from parent:", parent_message)

    # Message from child to parent
    child_message = "Hello from child!"
    child_to_parent.send(child_message)
    print("Child: Sent response to parent.")

def parent_child_communication():
    # Create two pipes: one for parent-to-child and one for child-to-parent communication
    parent_to_child, child_to_parent = multiprocessing.Pipe()

    # Message from parent to child
    parent_message = "Hello from parent!"
    parent_to_child.send(parent_message)
    print("Parent: Sent message to child.")

    # Start child process
    p = multiprocessing.Process(target=child_process, args=(parent_to_child, child_to_parent))
    p.start()

    # Read response from the child
    child_response = child_to_parent.recv()
    print("Parent: Received response from child:", child_response)

    # Wait for child to finish
    p.join()

if __name__ == "__main__":
    parent_child_communication()
