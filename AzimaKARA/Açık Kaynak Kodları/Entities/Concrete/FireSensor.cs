﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entities.Concrete
{
    public class FireSensor
    {
        public int Id { get; set; }
        public int isFire { get; set; }
        public DateTime date { get; set; }
    }
}
