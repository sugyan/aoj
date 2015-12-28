def calc(h)
  a = [0, 0]
  h.each_cons(2) do |p, n|
    a = [[a[0], n - p].max, [a[1], p - n].max]
  end
  a
end
gets.to_i.times do
  gets
  h = gets.split.map(&:to_i)
  puts calc(h).join(' ')
end
