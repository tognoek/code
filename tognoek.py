def normalize_string(s):
    # Remove leading and trailing whitespace
    s = s.strip()

    # Handle capitalization and punctuation
    result = []
    capitalize_next = True
    i = 0

    while i < len(s):
        if s[i] in ".:!?":
            result.append(s[i])
            if i + 1 < len(s) and s[i + 1] != ' ':
                result.append(' ')
            capitalize_next = True
            i += 1
        elif s[i].isalpha() or s[i].isdigit():
            if capitalize_next:
                result.append(s[i].upper())
                capitalize_next = False
            else:
                result.append(s[i])
            i += 1
        elif s[i].isspace():
            if result and result[-1] != ' ':
                result.append(' ')
            while i < len(s) and s[i].isspace():
                i += 1
        else:
            result.append(s[i])
            capitalize_next = False
            i += 1

    normalized = ''.join(result)

    # Remove extra spaces before punctuation
    normalized = normalized.replace(' .', '.')
    normalized = normalized.replace(' :', ':')
    normalized = normalized.replace(' !', '!')
    normalized = normalized.replace(' ?', '?')
    normalized = normalized.replace(' ,', ',')

    # Check if the string is already normalized
    if s == normalized:
        return "1\n*"
    else:
        return f"0\n{normalized}"


def tognoek():
    # Mở tệp để đọc
    with open("protist.inp", "r") as input_file:
        input_string = input_file.read().split()

    


    with open("protist.out", "w") as output_file:
        output_file.write(normalize_string(input_string))





def zgye():
    n = int(input())
    print(2 ** n)

tognoek()