S = gets.chomp

alphabet = ('a'..'z').to_a

answer = ''

S.each_char do |c|
  answer += format("%02d", alphabet.index(c) + 1)
end

puts answer
