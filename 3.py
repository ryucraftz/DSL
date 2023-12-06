def longest_word(string):
    words = string.split()
    if not words:
        return None
    return max(words, key=len)

def char_frequency(string, char):
    return string.count(char)

def is_palindrome(string):
    clean_string = ''.join(char.lower() for char in string if char.isalnum())
    return clean_string == clean_string[::-1]

def first_substring_index(main_string, substring):
    return main_string.find(substring)

def word_occurrences(string):
    words = string.split()
    word_count = {}
    for word in words:
        word_count[word] = word_count.get(word, 0) + 1
    return word_count

def main():
    input_string = "Hello, how are you? How is your day going?"
    
    longest_word_result = longest_word(input_string)
    print("a) Word with the longest length:", longest_word_result)
    
    char_to_check = 'o'
    char_frequency_result = char_frequency(input_string, char_to_check)
    print(f"b) Frequency of '{char_to_check}': {char_frequency_result}")
    
    palindrome_result = is_palindrome(input_string)
    print("c) Is the string a palindrome?", palindrome_result)
    
    substring_to_find = "are"
    first_substring_index_result = first_substring_index(input_string, substring_to_find)
    print(f"d) Index of the first occurrence of '{substring_to_find}': {first_substring_index_result}")
    
    word_occurrences_result = word_occurrences(input_string)
    print("e) Word occurrences:", word_occurrences_result)

if __name__ == "__main__":
    main()
