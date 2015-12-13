def calc(s, d)
  return d - s if d - s < 2
  m = s % 2 + d % 2
  m + calc((s / 2.0).ceil, d / 2)
end
gets.to_i.times do
  puts calc(*gets.split.map(&:to_i))
end
