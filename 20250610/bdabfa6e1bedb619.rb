S = gets.chomp

S.each_char do |c|
  if ('A'..'Z').include?(c)
    puts 'Yes'

    return
  end
end

puts 'No'
