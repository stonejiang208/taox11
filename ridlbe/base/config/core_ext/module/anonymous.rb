#--------------------------------------------------------------------
# @file    anonymous.rb
# @author  Martin Corino
#
# @brief   ActiveSupport style extension method for Module
#
# @copyright Copyright (c) Remedy IT Expertise BV
# Chamber of commerce Rotterdam nr.276339, The Netherlands
#--------------------------------------------------------------------

require 'ridlbe/base/config/core_ext/object/blank'

class Module
  # A module may or may not have a name.
  #
  #   module M; end
  #   M.name # => "M"
  #
  #   m = Module.new
  #   m.name # => ""
  #
  # A module gets a name when it is first assigned to a constant. Either
  # via the +module+ or +class+ keyword or by an explicit assignment:
  #
  #   m = Module.new # creates an anonymous module
  #   M = m          # => m gets a name here as a side-effect
  #   m.name         # => "M"
  #
  def anonymous?
    # Uses blank? because the name of an anonymous class is an empty
    # string in 1.8, and nil in 1.9.
    name.blank?
  end
end
