def calc(d)
  loop.with_index do |_, i|
    next if i == 0
    n = (i * Math::PI).to_i
    n += 1 if Math::PI > (n + 0.5) / i
    if (Math::PI - 1.0 * n / i).abs < d
      return "#{n}/#{i}"
    end
  end
end
loop do
  d = gets.to_f
  break if d == 0.0
  puts calc(d)
end
