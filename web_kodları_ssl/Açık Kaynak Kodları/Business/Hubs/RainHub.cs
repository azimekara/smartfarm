using Business.Abstract;
using Microsoft.AspNetCore.SignalR;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Business.Hubs
{
    public class RainHub: Hub
    {
        private readonly IRainSensorService _rainSensorService;

        public RainHub(IRainSensorService rainSensorService)
        {
            _rainSensorService = rainSensorService;
        }

        public async Task GetEndDataRain()
        {
            await Clients.All.SendAsync("ReceivedEndData", _rainSensorService.GetEndData());
        }


    }
}
