def calc(a, y, o)
  results = o.map do |soc, air, aoc|
    r = a
    if soc == 0
      i = 0
      y.times do
        i += (r * air).to_i
        r -= aoc
      end
      r += i
    else
      y.times do
        r += (r * air).to_i - aoc
      end
    end
    r
  end
  results.max
end
gets.to_i.times do
  a = gets.to_i
  y = gets.to_i
  o = []
  gets.to_i.times do
    l = gets.split
    o.push([l[0].to_i, l[1].to_f, l[2].to_i])
  end
  puts calc(a, y, o)
end
