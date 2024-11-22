'''
 El Primos: 
 Ferhat Kunduracı (SchumacherFarad, ferhatkundurac), 
 Umut Özil (umut373), 
 Ali Emre Kaya (aliemre2023)
'''

def min_adjacent_swaps_to_group(arr, value):
    count = 0
    value_index = 0

    for i in range(len(arr)):
        if arr[i] == value:
            count += abs(i - value_index)
            value_index += 1
    
    return count

n = int(input())
sequence = list(map(int, input().split()))
arr = [0 if num % 2 == 0 else 1 for num in sequence]

min_swaps_zeros = min_adjacent_swaps_to_group(arr, 0)
min_swaps_ones = min_adjacent_swaps_to_group(arr, 1)

print(min(min_swaps_zeros, min_swaps_ones))