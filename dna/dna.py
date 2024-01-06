import csv
import sys

def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("incorrect input: ")
        exit()

    # TODO: Read database file into a variable
    with open(sys.argv[1]) as file:
        reader = csv.reader(file)
        data = list(reader)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as f:
        sequence = f.read()

    # TODO: Find longest match of each STR in DNA sequence
    matches = []
    for i in range(1, len(data[0])):
        matches.append(longest_match(sequence, data[0][i]))


    # TODO: Check database for matching profiles
    suspect = 'No Match'
    suspects = 0

    for i in range(1, len(data)):
        for j in range(len(matches)):
            if matches[j] == int(data[i][j+1]):
                suspects += 1

        if suspects == len(matches):
            suspect = data[i][0]
            break
        else:
            suspects = 0
    print(suspect)

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
