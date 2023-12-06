def calculate_average(marks):
    total_marks = sum(marks)
    num_students = len(marks)
    if num_students == 0:
        return 0
    return total_marks / num_students

def find_highest_and_lowest(marks):
    if not marks:
        return None, None
    highest = max(marks)
    lowest = min(marks)
    return highest, lowest

def count_absent_students(marks):
    return marks.count(-1)

def mark_with_highest_frequency(marks):
    if not marks:
        return None
    frequency_dict = {}
    for mark in marks:
        if mark in frequency_dict:
            frequency_dict[mark] += 1
        else:
            frequency_dict[mark] = 1
    max_frequency = max(frequency_dict.values())
    marks_with_max_frequency = [mark for mark, frequency in frequency_dict.items() if frequency == max_frequency]
    return marks_with_max_frequency

def main():
    marks = [90, 85, 92, 78, 92, 85, 90, 78, 92, 88, 78, -1, -1, -1]
    average_score = calculate_average(marks)
    print("a) The average score of the class:", average_score)

    highest, lowest = find_highest_and_lowest(marks)
    print("b) Highest score in the class:", highest)
    print(" Lowest score in the class:", lowest)

    absent_count = count_absent_students(marks)
    print("c) Count of students who were absent for the test:", absent_count)

    marks_with_max_frequency = mark_with_highest_frequency(marks)
    print("d) Mark(s) with the highest frequency:", marks_with_max_frequency)

if __name__ == "__main__":
    main()
