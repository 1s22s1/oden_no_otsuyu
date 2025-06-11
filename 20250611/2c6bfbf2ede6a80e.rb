arr = gets.chomp.split("").map(&:to_i)

puts arr.map{|e| ((e + 3) % 10).to_s }.join
