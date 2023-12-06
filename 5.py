def linear_search(student_roll_numbers, target_roll_number):
    for roll_number in student_roll_numbers:
        if roll_number == target_roll_number:
            return True
    return False

def sentinel_search(student_roll_numbers, target_roll_number):
    student_roll_numbers.append(target_roll_number)
    i = 0
    while student_roll_numbers[i] != target_roll_number:
        i += 1
    student_roll_numbers.pop()
    return i < len(student_roll_numbers)

def main():
    student_roll_numbers = [101, 105, 110, 115, 120, 125, 130]
    target_roll_number = int(input("Enter the roll number to search: "))

    result_linear = linear_search(student_roll_numbers, target_roll_number)
    if result_linear:
        print(f"Linear search: Student with roll number {target_roll_number} attended the training program.")
    else:
        print(f"Linear search: Student with roll number {target_roll_number} did not attend the training program.")

    result_sentinel = sentinel_search(student_roll_numbers, target_roll_number)
    if result_sentinel:
        print(f"Sentinel search: Student with roll number {target_roll_number} attended the training program.")
    else:
        print(f"Sentinel search: Student with roll number {target_roll_number} did not attend the training program.")

if __name__ == "__main__":
    main()
