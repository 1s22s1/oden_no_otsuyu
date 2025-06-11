M = gets.chomp

arr = M.split("").map(&:to_i)[0...-1]

sum = 0

arr.each_with_index do |e, i|
  if(i % 2 == 0)
    sum += e
  else
    sum += e * 2
  end
end

if (sum % 10) == M.split("").map(&:to_i)[-1]
  puts "Yes"
else
  puts "No"
end
