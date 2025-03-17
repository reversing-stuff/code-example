import re

import re


def process_file(input_file, output_file):
    with open(input_file, "r") as infile, open(output_file, "w") as outfile:
        for line in infile:
            parts = re.split(r'\s+', line.strip())  # Split by whitespace
            if len(parts) >= 3:  # Ensure the line has enough parts
                value = parts[1]  # Get the second hex number

                if value != "0x0000000000000000":  # Ignore zero values
                    hex_bytes = bytes.fromhex(value[2:])  # Convert hex string to bytes
                    reversed_bytes = hex_bytes[::-1]  # Reverse endianness
                    split_chunks = [f"0x{byte:02x}" for byte in reversed_bytes]  # Format each byte

                    outfile.write(", ".join(split_chunks) + "\n")  # Write output




# Example usage
input_filename = "bytearraydump.txt"   # Replace with your actual filename
output_filename = "processedbytearraydump.txt"  # Output file
process_file(input_filename, output_filename)
