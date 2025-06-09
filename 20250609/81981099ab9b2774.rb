S = gets.chomp

T = S.split('').uniq

if T.size == 1 && (0..9).include?(T[0].to_i)
  puts 'dangerous'
else
  puts 'safe'
end
