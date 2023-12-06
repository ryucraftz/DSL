def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        less_than_pivot = [x for x in arr[1:] if x <= pivot]
        greater_than_pivot = [x for x in arr[1:] if x > pivot]
        return quick_sort(less_than_pivot) + [pivot] + quick_sort(greater_than_pivot)

def display_top_scores(arr, top_count=5):
    if len(arr) < top_count:
        top_count = len(arr)
    print(f"Top {top_count} scores:")
    for i in range(top_count):
        print(f"{i + 1}. {arr[i]}%")

def main():
    percentages = [75.5, 82.0, 68.5, 90.2, 78.9, 88.3, 95.0, 70.8, 87.6, 92.4]
    sorted_percentages = quick_sort(percentages)
    print("After Quick Sort:", sorted_percentages)
    display_top_scores(sorted_percentages)

if __name__ == "__main__":
    main()
