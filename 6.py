def selection_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

def display_top_scores(arr, top_count=5):
    if len(arr) < top_count:
        top_count = len(arr)
    print(f"Top {top_count} scores:")
    for i in range(top_count):
        print(f"{i + 1}. {arr[i]}%")

def main():
    percentages = [75.5, 82.0, 68.5, 90.2, 78.9, 88.3, 95.0, 70.8, 87.6, 92.4]

    selection_sort(percentages)
    print("After Selection Sort:", percentages)
    display_top_scores(percentages)

    bubble_sort(percentages)
    print("\nAfter Bubble Sort:", percentages)
    display_top_scores(percentages)

if __name__ == "__main__":
    main()

