import re

# Sample input files
nodes_file_path = 'map.txt'
bytearray_file_path = 'bytearray.txt'

# Initialize the dictionary to act like std::map<int, std::pair<int, int>>
my_map = {}

# Define regex pattern to extract Node Address, Key, Value 1, and Value 2
pattern = re.compile(r'Node Address: (0x[0-9a-fA-F]+)\s*Key: (\d+)\s*Value 1: (\d+)\s*Value 2: (\d+)')

# Initialize list for bytearray data as std::vector<std::vector<uint8_t>>
bytearray_data = []

# Reading the nodes file
with open(nodes_file_path, 'r') as file:
    data = file.read()  # Read the entire file at once

    # Find all matches for the pattern
    matches = pattern.findall(data)

    # Fill the map with key and pair values
    for match in matches:
        key = int(match[1])  # Key is the integer after 'Key:'
        value1 = int(match[2])  # Value 1
        value2 = int(match[3])  # Value 2

        # Insert the data into the map (dictionary in Python)
        my_map[key] = (value1, value2)

# Output the filled map
print("Map of Nodes:")
for key, value in my_map.items():
    print(f'Key: {key}, Value: {value}')

# Reading the bytearray file and processing the data
with open(bytearray_file_path, 'r') as file:
    # Read the file line by line
    lines = file.readlines()

    for line in lines:
        # Remove leading/trailing whitespaces
        line = line.strip()

        # Remove '0x' prefix from the line (if any)
        line = line.replace('0x', '')

        # Ensure that the line has an even number of characters to form byte pairs
        if len(line) % 2 != 0:
            line = '0' + line  # Prepend a 0 if the length is odd

        # Split the cleaned line into byte pairs (2 characters per pair)
        byte_pairs = [line[i:i + 2] for i in range(0, len(line), 2)]

        # Convert each byte pair to an integer using base 16
        bytearray_data.append([int(byte, 16) for byte in byte_pairs])

# Output the bytearray data as nested lists (like std::vector<std::vector<uint8_t>>)
print("\nBytearray Data:")
for i, byte_list in enumerate(bytearray_data):
    print(f"{i}: {byte_list}")

# Assuming the my_map and bytearray_data from previous code

# Prepare a new vector of vectors based on the Key-Value pairs
xor_bytearray_data = []

# Iterate through the map to create the new vector
for key, (value1, value2) in my_map.items():
    idx = value1  # The index in the old bytearray
    xor_key = value2  # The XOR key

    # Get the bytearray from the old bytearray_data based on the idx (index)
    old_byte_array = bytearray_data[idx]

    # XOR each byte in the bytearray except the 0x00 bytes
    xorred_bytes = [byte ^ xor_key if byte != 0x00 else byte for byte in old_byte_array]

    # Reverse the byte order
    xorred_bytes.reverse()

    # Append the processed bytearray to the new vector
    xor_bytearray_data.append(xorred_bytes)

# Output the new XORed bytearray data in hexadecimal format
print("\nXORed Bytearray Data (in Hex):")
for i, byte_list in enumerate(xor_bytearray_data):
    hex_values = [f"0x{byte:02x}" for byte in byte_list]  # Format bytes as hex
    print(f"{i}: {', '.join(hex_values)}")
