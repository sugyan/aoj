def calc(n, l, s, t, u)
  ok = proc do |m|
    w, e, f = l.to_f, [], true
    2.times do |j|
      w = [w + m * s[0], l].min
      n.times do |i|
        w += (m - u[i]) * (t[i] - s[i])
        if w <= 0
          f = false
          break
        end
        w += m * (s[i + 1] - t[i]) if i < n - 1
        w = l if w > l
      end
      break unless f
      w = [w + m * (86400 - t[-1]), l].min
      e[j] = w
    end
    f && e[1] >= e[0]
  end
  ll, rr = 0.0, 1e6
  loop do
    m = (ll + rr) / 2
    return m if rr - ll < 1e-7
    if ok.call(m)
      rr = m
    else
      ll = m
    end
  end
end
loop do
  n, l = gets.split.map(&:to_i)
  break if n == 0
  s, t, u = [], [], []
  n.times do |i|
    s[i], t[i], u[i] = gets.split.map(&:to_i)
  end
  puts format('%.7f', calc(n, l, s, t, u))
end
