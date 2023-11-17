import ties.rt;
import ties.libc;

int ties::main()
{
  return ties::libc::puts(ties::rt::argv[0]);
}

