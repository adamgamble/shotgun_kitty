require 'yaml'
configuration = YAML.load_file("config/arduino.yml")
file = File.join(File.dirname(__FILE__), "shotgun_kitty.ino")
executable = configuration["arduino"]["executable"]
arduino_task = "#{executable} #{file}"

task :verify do |t|
  puts `#{arduino_task} --verify`
end

task :upload do |t|
  puts `#{arduino_task} --upload`
end

task :default => [:verify]
