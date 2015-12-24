def calc(s)
  c, l = 0, s.size
  if l.odd?
    c += 1 if s[l / 2] < 42
  end
  (0 .. l / 2 - 1).each do |i|
    if s[i] < 42
      c += 1 if (s[i] - s[l - i - 1]).abs != 1
    else
      c += 1 if s[i] != s[l - i - 1]
    end
  end
  c
end
1.times do
  s = gets.chomp.bytes
  puts calc(s)
end
