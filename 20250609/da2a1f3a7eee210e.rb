S = gets.chomp

if (/\A\d{4}\z/).match?(S)
  puts 'valid'
else
  puts 'invalid'
end
