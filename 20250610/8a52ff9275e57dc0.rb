a, b, c, d = gets.chomp.split("").map(&:to_i)

if ([a, b, c, d].uniq.size == 1) || (a + 1 == b && b + 1 == c && c + 1 == d) || (a - 1 == b && b - 1 == c && c - 1 == d)
  puts 'dangerous'
else
  puts 'safe'
end
