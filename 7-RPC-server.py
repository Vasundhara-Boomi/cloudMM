import socket
import json

def add(args):
    return sum(args)

def subtract(args):
    return args[0] - args[1]

def multiply(args):
    result = 1
    for arg in args:
        result *= arg
    return result

def divide(args):
    if args[1] == 0:
        return "Error: Division by zero"
    return args[0] / args[1]

def handle_request(request):
    function = request.get("function")
    args = request.get("args")

    # Map the function name to the corresponding function
    functions = {
        "add": add,
        "subtract": subtract,
        "multiply": multiply,
        "divide": divide
    }

    # Check if the function exists
    if function in functions:
        return functions[function](args)
    else:
        return "Error: Function not found"

def start_server(host='127.0.0.1', port=65432):
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((host, port))
    server_socket.listen(1)

    print(f"Server listening on {host}:{port}...")

    while True:
        client_socket, client_address = server_socket.accept()
        print(f"Connection established with {client_address}")

        # Receive the request data
        request_data = client_socket.recv(1024).decode()
        request = json.loads(request_data)

        # Handle the request and get the result
        result = handle_request(request)

        # Send the result back to the client
        response = json.dumps({"result": result})
        client_socket.sendall(response.encode())

        # Close the client connection
        client_socket.close()

if __name__ == "__main__":
    start_server()
