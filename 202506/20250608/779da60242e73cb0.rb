N = gets.chomp.to_i
S = gets.chomp

S.each_char do |c|
    if(('a'..'z').include?(c))
        puts 'lowercase'
        next
    end

    if(('A'..'Z').include?(c))
        puts 'uppercase'
        next
    end

    if(('0'..'9').include?(c))
        puts 'digit'
        next
    end

    puts c
end
