import re


def replace_registers(line):
    mapping = {
        0: "RAX", 1: "RBX", 2: "RCX", 3: "RDX",
        13: "param_2", 14: "param_1"
    }

    def replace_match(match):
        num = int(match.group(1))
        return f"{mapping[num]}" if num in mapping else f"local_{num}"

    return re.sub(r'\[(\d+)\]', replace_match, line)


def process_file(input_filename, output_filename):
    with open(input_filename, 'r') as infile, open(output_filename, 'w') as outfile:
        for line in infile:
            outfile.write(replace_registers(line))


def main():
    input_filename = "processedbytearraydump3.txt"  # Change this to your input filename
    output_filename = "processedbytearraydump4.txt"  # Change this to your output filename
    process_file(input_filename, output_filename)
    print(f"Processed file saved as {output_filename}")


if __name__ == "__main__":
    main()
