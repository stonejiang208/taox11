#---------------------------------------------------------------------
# @file   run_test.pl
# @author Marcel Smit
#
# @copyright Copyright (c) Remedy IT Expertise BV
# Chamber of commerce Rotterdam nr.276339, The Netherlands
#---------------------------------------------------------------------
eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# -*- perl -*-

use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::TestTarget;

my $server = PerlACE::TestTarget::create_target(2) || die "Create target 2 failed\n";

$threads = '3';

$SV = $server->CreateProcess ("manipulation", "-n $threads");

$test = $SV->SpawnWaitKill ($server->ProcessStartWaitInterval() * 2);

if ($test != 0) {
    print STDERR "ERROR: test returned $test\n";
    exit 1;
}

exit 0;
