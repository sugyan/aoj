def calc()
  a, s, q = [0] * 100, [0] * 17, []
  loop.with_index do |_, t|
    s.each.with_index do |e, i|
      s[i] -= 1 if e > 0
    end
    q.push(t / 5) if t % 5 == 0
    while q[0]
      f = false
      g = q[0]
      n = g % 5 == 1 ? 5 : 2
      s.each_cons(n).with_index do |c, i|
        if c.all? { |e| e == 0 }
          n.times do |j|
            s[i + j] = 17 * (g % 2) + 3 * (g % 3) + 19
          end
          a[g] = t - g * 5
          return a if g == 99
          q.shift
          f = true
          break
        end
      end
      break unless f
    end
  end
end
1.times do
  a = calc
  loop do
    n = gets
    break unless n
    puts a[n.to_i]
  end
end
