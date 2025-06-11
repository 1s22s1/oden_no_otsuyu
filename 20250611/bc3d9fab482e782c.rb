N = gets.chomp
arr = N.split("").map(&:to_i)

sum = 0

arr.each_with_index do |e, i|
  if(i % 2 == 0)
    sum += e
  else
    sum += e * 2
  end
end

puts N + (sum % 10).to_s
