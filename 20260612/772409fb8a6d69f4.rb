S = gets.chomp

arr = S.split("").map do |e|
  n = e.to_i - 3
  if n < 0
    n += 10
  end

  n.to_s
end

puts arr.join
