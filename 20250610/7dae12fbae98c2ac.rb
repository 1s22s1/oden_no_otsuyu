S = gets.chomp

unless (6..64).include?(S.length)
  puts 'invalid'

  return
end

score = 0

if S.length >= 10
  score += 1
end

if S.split("").any?{|c| ('a'..'z').include?(c) }
  score += 1
end

if S.split("").any?{|c| ('A'..'Z').include?(c) }
  score += 1
end

if S.split("").any?{|c| ('0'..'9').include?(c) }
  score += 1
end

if S.split("").any?{|c| ['!', '?', '@'].include?(c) }
  score += 1
end

case score
when 2
  puts 'weak'
when 3
  puts 'medium'
else
  puts 'strong'
end
