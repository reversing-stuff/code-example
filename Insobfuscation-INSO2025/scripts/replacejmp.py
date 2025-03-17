import re


def replace_jumps_with_labels(input_file, output_file):
    with open(input_file, 'r') as f:
        lines = f.readlines()

    label_map = {}  # Store line number to label mapping
    offset_map = {}  # Store the offset caused by inserted labels
    updated_lines = []
    offset = 0

    # First pass: Identify jump targets and create labels
    for i, line in enumerate(lines):
        match = re.match(r'^(JMP|JNZ|JG) (\d+)', line)
        if match:
            jump_target = int(match.group(2))
            label = f'line{jump_target}'
            label_map[jump_target] = label

    # Second pass: Insert labels and adjust jump offsets
    for i, line in enumerate(lines):
        line_number = i + 1  # Convert index to 1-based line number
        adjusted_line_number = line_number + offset  # Account for previous shifts

        if line_number in label_map:
            updated_lines.append(f'{label_map[line_number]}:\n')  # Insert label before the line
            offset += 1  # Increase offset due to inserted label

        # Adjust jump targets based on offset
        def adjust_jump(match):
            jump_type, target = match.groups()
            target = int(target)
            adjusted_target = target + sum(1 for key in label_map if key < target)  # Adjust for inserted labels
            return f'{jump_type} {label_map.get(target, adjusted_target)}'

        updated_line = re.sub(r'(JMP|JNZ|JG) (\d+)', adjust_jump, line)
        updated_lines.append(updated_line)

    # Write to output file
    with open(output_file, 'w') as f:
        f.writelines(updated_lines)

    print(f"Processed file written to {output_file}")


# Example usage
input_filename = "processedbytearraydump2.txt"
output_filename = "processedbytearraydump3.txt"
replace_jumps_with_labels(input_filename, output_filename)
