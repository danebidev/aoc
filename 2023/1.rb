sum = 0

File.foreach("input") { |line|
    first = ""
    last = ""
    line.split("").each { |char|
        break unless char != "\n"
        if char =~ /[1-9]/ then
            if first == "" then
                first = char
            end
            last = char
        end
    }
    sum += Integer(first + last)
}

puts sum